#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetVerticalSync(false);
	ofSetFrameRate(60);

	currentSound = 0;
	playedListSize = 9;
	// load our transition matrix into the markov chain addOn
	ofxMC::Matrix matrix("transitionMatrix.txt");
	markov.setup(matrix, 0);
	int numSamples = markov.getStatesNumber();

	// load sample files into a vector of sample player objects
	for (int i = 0; i < numSamples; i++) {
		ofSoundPlayer newSample; // make a new sound player object
		newSample.load("sample" + ofToString(i + 1) + ".wav"); // generate the filename to load starting from 1
		newSample.setLoop(false);
		samples.push_back(newSample); // push the sample into the vector of soundplayer objects
	}
	samples[currentSound].play(); // start the first one

	playedList.push_back(currentSound);
}
//-------------------------------------------------------------- 
void ofApp::update(){
	if (samples[currentSound].isPlaying() == false) { // if sample finished
	   // play next sample from markov chain object
		markov.update();
		currentSound = markov.getState();
		samples[currentSound].play();
		// always play basic drum loop
		samples[0].play();
		if (playedList.size() > playedListSize) { // only keep the last 12 samples in the list of samples being played
			playedList.erase(playedList.begin()); // if more than 12 then erase the first one
		}
		playedList.push_back(currentSound); // add our new one to the list of played samples
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

}