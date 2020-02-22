#pragma once

#include "ofMain.h"
#include "ofxMarkovChain.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();


		vector<ofSoundPlayer> samples;
		ofxMC::MarkovChain markov;
		int currentSound, playedListSize;
		vector<int> playedList;
};
