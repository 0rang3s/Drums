#pragma once

#include "ofMain.h"
#include "ofxGui.h"


class ofApp : public ofBaseApp{
	
public:
	void setup();
	void update();
	void draw();
	
	void exit();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);		

	void circleResolutionChanged(int& circleResolution);

	void volumeSnareChanged(float& volume);
	void volumeBassChanged(float& volume);
	void volumeHiTomChanged(float& volume);
	void volumeCymbalChanged(float& volume);

	void speedSnareChanged(float& speed);
	void speedBassChanged(float& speed);
	void speedHiTomChanged(float& speed);
	void speedCymbalChanged(float& speed);

	bool bHide;

	ofxFloatSlider radiusSnare;
	ofxColorSlider colorSnare;
	ofxVec2Slider centerSnare;
	ofxIntSlider circleResolutionSnare;
	ofxToggle filledSnare;

	ofxFloatSlider radiusBass;
	ofxColorSlider colorBass;
	ofxVec2Slider centerBass;
	ofxIntSlider circleResolutionBass;
	ofxToggle filledBass;

	ofxFloatSlider radiusHiTom;
	ofxColorSlider colorHiTom;
	ofxVec2Slider centerHiTom;
	ofxIntSlider circleResolutionHiTom;
	ofxToggle filledHiTom;

	ofxFloatSlider radiusCymbal;
	ofxColorSlider colorCymbal;
	ofxVec2Slider centerCymbal;
	ofxIntSlider circleResolutionCymbal;
	ofxToggle filledCymbal;

	ofxButton ringButton;
	ofxButton snareButton;
	ofxLabel screenSize;

	ofxFloatSlider pitchSnare, pitchBass, pitchHiTom, pitchCymbal;

	float snarePitch, bassPitch, hiTomPitch, cymbalPitch;

	ofxPanel gui;

	ofSoundPlayer snare, bass, hiTom, cymbal;

	ofParameter<float> volumeSnare, volumeBass, volumeHiTom, volumeCymbal;

	// Add these variables for speed control
	ofParameter<float> speedSnare, speedBass, speedHiTom, speedCymbal;
};

