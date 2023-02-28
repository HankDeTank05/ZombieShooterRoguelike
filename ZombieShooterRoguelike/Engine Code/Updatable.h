#ifndef UPDATABLE_H
#define UPDATABLE_H

class Updatable
{
public:
	Updatable();
	Updatable(const Updatable& rUpdatable);
	Updatable& operator=(const Updatable& rUpdatable);
	virtual ~Updatable();

	virtual void Update() = 0;
	
protected:
	virtual void EnqueueForUpdateRegistration() final;
	virtual void EnqueueForUpdateDeregistration() final;

private:
	void RegisterForUpdate();
	void DeregisterForUpdate();

private:
	// member variables go here
};

#endif