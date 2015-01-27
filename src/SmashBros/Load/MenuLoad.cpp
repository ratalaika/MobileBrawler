
#include "MenuLoad.h"

namespace SmashBros
{
	MenuLoad::MenuLoad(Window&window, const String&primaryDir)
	{
		assetManager = new AssetManager(window, primaryDir);
		primaryDirectory = primaryDir;
		secondaryDirectory = "";
	}
	
	MenuLoad::MenuLoad(Window&window, const String&primaryDir, const String&secondaryDir)
	{
		ArrayList<String> secondaryDirs;
		secondaryDirs.add(secondaryDir);
		assetManager = new AssetManager(window, primaryDir, secondaryDirs);
		primaryDirectory = primaryDir;
		secondaryDirectory = secondaryDir;
	}
	
	MenuLoad::~MenuLoad()
	{
		delete assetManager;
	}
	
	AssetManager* MenuLoad::getAssetManager() const
	{
		return assetManager;
	}
	
	const Dictionary& MenuLoad::getMenuBarProperties() const
	{
		return properties_menuBar;
	}
	
	const Dictionary& MenuLoad::getRulesBarProperties() const
	{
		return properties_rulesBar;
	}
	
	const Dictionary& MenuLoad::getCharacterSelectPanelProperties() const
	{
		return properties_charselectPanel;
	}
	
	const Image& MenuLoad::getCharacterSelectIconMask() const
	{
		return characterselect_iconmask;
	}
	
	const Image& MenuLoad::getStageSelectIconMask() const
	{
		return stageselect_iconmask;
	}
	
	void MenuLoad::load()
	{
		loadIconMasks();
		loadProperties();
		loadAssets();
	}
	
	void MenuLoad::reload()
	{
		characterselect_iconmask.clear();
		stageselect_iconmask.clear();
		
		properties_menuBar.clear();
		properties_rulesBar.clear();
		properties_charselectPanel.clear();
		
		loadIconMasks();
		loadProperties();
		
		assetManager->reload();
	}
	
	void MenuLoad::loadIconMasks()
	{
		//load character select icon mask
		bool success = characterselect_iconmask.loadFromFile(FileTools::combinePathStrings(primaryDirectory,"characterselect/icon_mask.png"));
		if(!success)
		{
			characterselect_iconmask.loadFromFile(FileTools::combinePathStrings(secondaryDirectory, "characterselect/icon_mask.png"));
		}
		
		//load stage select icon mask
		success = stageselect_iconmask.loadFromFile(FileTools::combinePathStrings(primaryDirectory,"stageselect/icon_mask.png"));
		if(!success)
		{
			stageselect_iconmask.loadFromFile(FileTools::combinePathStrings(secondaryDirectory, "stageselect/icon_mask.png"));
		}
	}
	
	void MenuLoad::loadProperties()
	{
		//load menu bar properties
		bool success = properties_menuBar.loadFromFile(FileTools::combinePathStrings(primaryDirectory,"elements/menu_bar.plist"));
		if(!success)
		{
			properties_menuBar.loadFromFile(FileTools::combinePathStrings(secondaryDirectory, "elements/menu_bar.plist"));
		}
		
		//load rules bar properties
		success = properties_rulesBar.loadFromFile(FileTools::combinePathStrings(primaryDirectory,"elements/rules_bar.plist"));
		if(!success)
		{
			properties_rulesBar.loadFromFile(FileTools::combinePathStrings(secondaryDirectory, "elements/rules_bar.plist"));
		}
		
		//load character select panel properties
		success = properties_charselectPanel.loadFromFile(FileTools::combinePathStrings(primaryDirectory,"characterselect/panel.plist"));
		if(!success)
		{
			properties_charselectPanel.loadFromFile(FileTools::combinePathStrings(secondaryDirectory, "characterselect/panel.plist"));
		}
	}
	
	void MenuLoad::loadAssets()
	{
		BatchLoader* batchLoader = new BatchLoader(assetManager);
		
		batchLoader->addTexture("backgrounds/main.png");
		
		batchLoader->addTexture("buttons/back.png");
		batchLoader->addTexture("buttons/main/group.png");
		batchLoader->addTexture("buttons/main/solo.png");
		batchLoader->addTexture("buttons/group/rules.png");
		batchLoader->addTexture("buttons/group/smash.png");
		batchLoader->addTexture("buttons/solo/training.png");
		
		batchLoader->addTexture("characterselect/chip_cpu.png");
		batchLoader->addTexture("characterselect/chip_p1.png");
		batchLoader->addTexture("characterselect/chip_p2.png");
		batchLoader->addTexture("characterselect/chip_p3.png");
		batchLoader->addTexture("characterselect/chip_p4.png");
		batchLoader->addTexture("characterselect/panel_background_p1.png");
		batchLoader->addTexture("characterselect/panel_background_p2.png");
		batchLoader->addTexture("characterselect/panel_background_p3.png");
		batchLoader->addTexture("characterselect/panel_background_p4.png");
		batchLoader->addTexture("characterselect/panel_background_cpu.png");
		batchLoader->addTexture("characterselect/panel_background_na.png");
		batchLoader->addTexture("characterselect/panel_background_blank.png");
		batchLoader->addTexture("characterselect/panel_overlay_p1.png");
		batchLoader->addTexture("characterselect/panel_overlay_p2.png");
		batchLoader->addTexture("characterselect/panel_overlay_p3.png");
		batchLoader->addTexture("characterselect/panel_overlay_p4.png");
		batchLoader->addTexture("characterselect/panel_overlay_cpu.png");
		batchLoader->addTexture("characterselect/panel_overlay_na.png");
		batchLoader->addTexture("characterselect/panel_overlay_blank.png");
		batchLoader->addTexture("characterselect/icon_frame.png");
		batchLoader->addTexture("characterselect/readytofight_banner.png");
		
		batchLoader->addTexture("elements/button_arrow_down.png");
		batchLoader->addTexture("elements/button_arrow_left.png");
		batchLoader->addTexture("elements/button_arrow_right.png");
		batchLoader->addTexture("elements/button_arrow_up.png");
		batchLoader->addTexture("elements/headerbar_full.png");
		batchLoader->addTexture("elements/headerbar_small.png");
		batchLoader->addTexture("elements/menu_bar.png");
		batchLoader->addTexture("elements/rules_bar.png");
		
		batchLoader->addFont("fonts/default.ttf");
		
		batchLoader->addTexture("titlescreen/logo.png");
		batchLoader->addTexture("titlescreen/background.png");
		
		batchLoader->loadAll();
		
		delete batchLoader;
	}
	
	void MenuLoad::unload()
	{
		assetManager->unload();
		properties_menuBar.clear();
		properties_rulesBar.clear();
		properties_charselectPanel.clear();
		
		characterselect_iconmask.clear();
		stageselect_iconmask.clear();
	}
}