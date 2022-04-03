#include "Effect.h"
#include "Effect.h"


Effect::Effect(ID id, std::string description, int activeDuration) : _id(id), _description(description), _initialActiveDuration(activeDuration), _remainingActiveDuration(activeDuration) {}

Effect::~Effect(){}

int Effect::updateActiveDuration()
{
	if (_remainingActiveDuration == 0) return 0;

	_remainingActiveDuration = std::max(_remainingActiveDuration - 1, 0);

	return _remainingActiveDuration;
}
