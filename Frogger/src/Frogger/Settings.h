/*
 * Settings.h
 *
 *  Created on: 15-mei-2016
 *      Author: Kris
 */

#ifndef FROGGER_SETTINGS_H_
#define FROGGER_SETTINGS_H_
namespace Frogger
{
	class Settings {
	public:
		virtual void ReadHigscore(int[]) =0;
		virtual void WriteToFile(int[]) =0;
		virtual ~Settings();
	};
}
#endif /* FROGGER_SETTINGS_H_ */
