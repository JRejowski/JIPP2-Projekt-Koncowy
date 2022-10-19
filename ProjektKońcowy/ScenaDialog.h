//
// Created by Yonasz on 22.01.2022.
//

#ifndef JIPP2_SCENADIALOG_H
#define JIPP2_SCENADIALOG_H

#include "Scena.h"
#include <Windows.h>
#include <vector>

using namespace std;

template<typename T>
class ScenaDialog: public Scena{
public:
    /**
     * Function that updates dialog scene (prints subsequent lines with 2 second delay between lines)
     * @return false when all of the lines are printed
     */
    bool update();
    /**
     * Function that adds a line to vector
     * @param x - line that you want to push into the vector
     */
    void addLine(const T& x);
private:
    vector<T> dialog;

};



template<typename T>
void ScenaDialog<T>::addLine(const T& x)
{
	dialog.push_back(x);
}

template<typename T>
bool ScenaDialog<T>::update() {

	for (const T& x : dialog)
	{
		cout << x << endl;
		Sleep(2000);
	}
	return false;



}

#endif //JIPP2_SCENADIALOG_H
