#ifndef TDRAWABLE_ATTORNEY_H
#define TDRAWABLE_ATTORNEY_H

// forward declarations
class TDrawable;

class TDrawableAttorney
{
public:

	class Registration
	{
	private:
		friend class TDrawRegistrationCommand;
		friend class TDrawDeregistrationCommand;
		
		static void RegisterForDraw(TDrawable* pDrawable);
		static void DeregisterForDraw(TDrawable* pDrawable);
	};
};

#endif