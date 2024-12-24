#include "EngineKillTimer.h"

// class EngineKillTimer

// Object | public

// Events
void Test::EngineKillTimer::onPreCoreUpdate() {
	IT::InTimeEngine* engine = IT::InTimeEngine::getSingleton();
	if (engine->coreTime.getTime() > std::chrono::seconds(3))
		engine->stop();
}
