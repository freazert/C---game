/*
 * Sound.h
 *
 *  Created on: 19-jun.-2016
 *      Author: Kris
 */

#ifndef FROGGER_SOUND_H_
#define FROGGER_SOUND_H_

namespace Frogger {

class Sound {
public:
	virtual void StartGameOverSound() =0;
	virtual void StartMusic()= 0;
	virtual void ResumeMusic()= 0;
	virtual void PauseMusic() = 0;
	virtual ~Sound()=0;
};

} /* namespace Frogger */

#endif /* FROGGER_SOUND_H_ */
