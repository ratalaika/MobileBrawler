
#include "Drawable.h"
#include "../Exception/IllegalArgumentException.h"
#include "../Exception/IllegalStateException.h"
#include "../Utilities/ArrayList.h"
#include "../Utilities/Pair.h"
#include <mutex>

#pragma once

namespace GameLibrary
{
	typedef void(*CompletionCallback)(void*);

	class ScreenElement : public Drawable
	{
		friend class Screen;
		friend class ScreenManager;
	private:
		Window*window;

		RectangleF frame;

		ScreenElement* parentElement;
		ArrayList<ScreenElement*> childElements;
		ArrayList<ScreenElement*> removedChildElements;

		mutable bool updatingElements;
		bool relativePosition;

		Color backgroundColor;

		virtual void setWindow(Window*window);

	protected:
		virtual void drawBackground(ApplicationData appData, Graphics graphics) const;
		virtual void drawElements(ApplicationData appData, Graphics graphics) const;

		virtual void onRemoveFromWindow(Window*window);
		virtual void onAddToWindow(Window*window);

	public:
		ScreenElement();
		ScreenElement(const RectangleF&frame);
		ScreenElement(const ScreenElement&) = delete;
		virtual ~ScreenElement();

		ScreenElement& operator=(const ScreenElement&) = delete;

		virtual void update(ApplicationData appData);
		virtual void draw(ApplicationData appData, Graphics graphics) const;

		virtual void setFrame(const RectangleF&frame);

		virtual RectangleF getFrame() const;
		Vector2f getCenter() const;

		void addChildElement(ScreenElement*element);
		void removeFromParentElement();
		void bringChildElementToFront(ScreenElement*element);

		const ArrayList<ScreenElement*>& getChildElements() const;
		ScreenElement* getParentElement() const;

		void enableRelativePositioning(bool);
		bool relativePositioningEnabled() const;
		
		void setBackgroundColor(const Color&);
		const Color& getBackgroundColor() const;
	};
}