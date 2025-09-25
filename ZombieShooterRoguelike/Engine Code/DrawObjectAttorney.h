#ifndef DRAW_OBJECT_ATTORNEY_H
#define DRAW_OBJECT_ATTORNEY_H

// forward declarations
class DrawObject;

class DrawObjectAttorney
{
public:

	class Registration
	{
	private:
		friend class TDrawRegistrationCommand;
		friend class TDrawDeregistrationCommand;
		
		static void RegisterForDraw(DrawObject* pDrawable);
		static void DeregisterForDraw(DrawObject* pDrawable);
	};
};

#endif