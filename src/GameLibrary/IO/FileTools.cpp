
#include "FileTools.h"
#include "../Utilities/PlatformChecks.h"	

#include <dirent.h>
#include <sys/stat.h>

#if defined(TARGETPLATFORM_WINDOWS)
	#include <direct.h>
#else
	#include <unistd.h>
#endif

namespace GameLibrary
{
	String FileTools::getCurrentWorkingDirectory()
	{
		char buffer[FILENAME_MAX];
		buffer[0] = '\0';
		#if defined(TARGETPLATFORM_WINDOWS)
			if(_getcwd(buffer, FILENAME_MAX) == nullptr)
			{
				return "";
			}
		#else
			if(getcwd(buffer, FILENAME_MAX) == nullptr)
			{
				return "";
			}
		#endif
		return buffer;
	}
	
	bool FileTools::readEntriesFromDirectory(const String&directory, ArrayList<DirectoryEntry>*entries, String*error)
	{
		if(entries == nullptr)
		{
			throw IllegalArgumentException("entries", "null");
		}
		DIR*dir = opendir(directory);
		if(dir==NULL)
		{
			//TODO add checking of errno
			if(error!=nullptr)
			{
				*error = "Unable to open directory";
			}
			return false;
		}
		entries->clear();
		struct dirent *entry = readdir(dir);
		while (entry != NULL)
		{
			DirectoryEntry item;
			item.name = entry->d_name;
			switch(entry->d_type)
			{
				case DT_REG:
				item.type = ENTRYTYPE_FILE;
				break;
					
				case DT_DIR:
				item.type = ENTRYTYPE_FOLDER;
				break;
					
				case DT_LNK:
				{
					struct stat s;
					String path = directory + '/' + item.name;
					if(stat(path, &s)==0)
					{
						if((s.st_mode&S_IFMT) == S_IFDIR)
						{
							item.type = ENTRYTYPE_LINK_FOLDER;
						}
						else if((s.st_mode&S_IFMT) == S_IFREG)
						{
							item.type = ENTRYTYPE_LINK_FILE;
						}
						else
						{
							item.type = ENTRYTYPE_LINK;
						}
					}
					else
					{
						item.type = ENTRYTYPE_LINK;
					}
				}
				break;
					
				default:
				item.type = ENTRYTYPE_UNKNOWN;
				break;
			}
			if(!(item.name.equals(".") || item.name.equals("..")))
			{
				entries->add(item);
			}
			entry = readdir(dir);
		}
		closedir(dir);
		return true;
	}
	
	String FileTools::combinePathStrings(const String&first, const String&second)
	{
		String fullpath;
		if(first.length() == 0)
		{
			fullpath = second;
		}
		else
		{
			if(first.charAt(first.length()-1)=='/')
			{
				fullpath = first + second;
			}
			else
			{
				fullpath = first + '/' + second;
			}
		}
		return fullpath;
	}
}
