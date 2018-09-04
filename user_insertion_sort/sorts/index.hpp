#include "../storage.hpp"
#include "step_types.hpp"
#include "active.hpp"

namespace Sorts
{
    const unsigned int INTERVAL = 1000;

    void setup(){

    }

    bool dataSortable(){
        return Storage::count > 1;
    }

    void sortData(){
        IO::outputDataPlain();
        if (!Active::isNextStep()){
            return;
        }
        while(Active::isNextStep()){
            short int nextStepType = Active::nextStepType();
            unsigned short int nextStepTarget1 = Active::nextStepTarget1();
            unsigned short int nextStepTarget2 = Active::nextStepTarget2();

            switch(nextStepType){
                case StepTypes::COMPARE:
                    IO::outputDataFormatPair(nextStepTarget1, nextStepTarget2, '{', '}');
                    break;
                case StepTypes::SWAP:
                    IO::ledOn();
                    IO::outputDataFormatPair(nextStepTarget1, nextStepTarget2, '[', ']');
                    break;
                default:
                    IO::outputDataPlain();
            }
            Active::performNextStep();
            delay(INTERVAL);
            IO::ledOff();
        }
        IO::outputDataPlain();
    }
}
