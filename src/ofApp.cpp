#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetVerticalSync(true);

	// we add this listener before setting up so the initial circle resolution is correct


	// Adding listeers for each of the cirlces (drums)

	circleResolutionSnare.addListener(this, &ofApp::circleResolutionChanged);
	circleResolutionBass.addListener(this, &ofApp::circleResolutionChanged);
	circleResolutionHiTom.addListener(this, &ofApp::circleResolutionChanged);
	circleResolutionCymbal.addListener(this, &ofApp::circleResolutionChanged);

	gui.setup(); // most of the time you don't need a name

	//Adding the sliders for the drums set up (you can adjust the radius, size, color, location etc from the sliders 
	gui.add(filledSnare.setup("fill", true));
	gui.add(radiusSnare.setup("radius", 75, 10, 300));
	gui.add(centerSnare.setup("center", { ofGetWidth() * .65, ofGetHeight() * .37 }, { 0, 0 }, { ofGetWidth(), ofGetHeight() }));
	gui.add(colorSnare.setup("colorSnare", ofColor(100, 100, 140), ofColor(0, 0), ofColor(255, 255)));
	gui.add(circleResolutionSnare.setup("circle res", 90, 3, 90));

	gui.add(filledBass.setup("fill", true));
	gui.add(radiusBass.setup("radius", 125, 10, 300));
	gui.add(centerBass.setup("center", { ofGetWidth() * .5, ofGetHeight() * .5 }, { 0, 0 }, { ofGetWidth(), ofGetHeight() }));
	gui.add(colorBass.setup("colorBass", ofColor(150, 159, 150), ofColor(6, 6), ofColor(200, 200)));
	gui.add(circleResolutionBass.setup("circle res b", 90, 3, 90));

	gui.add(filledHiTom.setup("fill", true));
	gui.add(radiusHiTom.setup("radius", 75, 10, 300));
	gui.add(centerHiTom.setup("center", { ofGetWidth() * .35, ofGetHeight() * .4 }, { 0, 0 }, { ofGetWidth(), ofGetHeight() }));
	gui.add(colorHiTom.setup("colorHiTom", ofColor(200, 159, 200), ofColor(6, 6), ofColor(200, 200)));
	gui.add(circleResolutionHiTom.setup("circle res b", 90, 3, 90));

	gui.add(filledCymbal.setup("fill", true));
	gui.add(radiusCymbal.setup("radius", 100, 10, 300));
	gui.add(centerCymbal.setup("center", { ofGetWidth() * .3, ofGetHeight() * .2 }, { 0, 0 }, { ofGetWidth(), ofGetHeight() }));
	gui.add(colorCymbal.setup("colorSymbal", ofColor(150, 159, 250), ofColor(6, 6), ofColor(200, 200)));
	gui.add(circleResolutionCymbal.setup("circle res b", 90, 3, 90));


	gui.add(screenSize.setup("screen size", ofToString(ofGetWidth()) + "x" + ofToString(ofGetHeight())));

	//Loading all sounds 
	snare.load("Snare.wav");
	bass.load("bass.wav");
	hiTom.load("HiTom.wav");
	cymbal.load("Cymbal.wav");

	//Adding the pitch slider (only for visual you can change it using arrow keys) 
	gui.add(pitchSnare.setup("Pitch Snare", 1.0, 0.5, 2.0));
	gui.add(pitchBass.setup("Pitch Bass", 1.0, 0.5, 2.0));
	gui.add(pitchHiTom.setup("Pitch HiTom", 1.0, 0.5, 2.0));
	gui.add(pitchCymbal.setup("Pitch Cymbal", 1.0, 0.5, 2.0));

	//Adding listener for volume of each instrument
	volumeSnare.addListener(this, &ofApp::volumeSnareChanged);
	volumeBass.addListener(this, &ofApp::volumeBassChanged);
	volumeHiTom.addListener(this, &ofApp::volumeHiTomChanged);
	volumeCymbal.addListener(this, &ofApp::volumeCymbalChanged);

	//Addding sliders
	gui.add(volumeSnare.set("Volume Snare", 1.0, 0.0, 1.0));
	gui.add(volumeBass.set("Volume Bass", 1.0, 0.0, 1.0));
	gui.add(volumeHiTom.set("Volume HiTom", 1.0, 0.0, 1.0));
	gui.add(volumeCymbal.set("Volume Cymbal", 1.0, 0.0, 1.0));

	//Adding listener for speed of each instrument
	speedSnare.addListener(this, &ofApp::speedSnareChanged);
	speedBass.addListener(this, &ofApp::speedBassChanged);
	speedHiTom.addListener(this, &ofApp::speedHiTomChanged);
	speedCymbal.addListener(this, &ofApp::speedCymbalChanged);

	// Add sliders for speed control
	gui.add(speedSnare.set("Speed Snare", 1.0, 0.5, 5.0));
	gui.add(speedBass.set("Speed Bass", 1.0, 0.5, 5.0));
	gui.add(speedHiTom.set("Speed HiTom", 1.0, 0.5, 5.0));
	gui.add(speedCymbal.set("Speed Cymbal", 1.0, 0.5, 5.0));


	bHide = false;
}

//--------------------------------------------------------------z
void ofApp::exit() {

}

//--------------------------------------------------------------
void ofApp::volumeSnareChanged(float& volume) {
	snare.setVolume(volume);
}

void ofApp::volumeBassChanged(float& volume) {
	bass.setVolume(volume);
}

void ofApp::volumeHiTomChanged(float& volume) {
	hiTom.setVolume(volume);
}

void ofApp::volumeCymbalChanged(float& volume) {
	cymbal.setVolume(volume);
}

//--------------------------------------------------------------
void ofApp::speedSnareChanged(float& speed) {
	snare.setSpeed(speed);
}

void ofApp::speedBassChanged(float& speed) {
	bass.setSpeed(speed);
}

void ofApp::speedHiTomChanged(float& speed) {
	hiTom.setSpeed(speed);
}

void ofApp::speedCymbalChanged(float& speed) {
	cymbal.setSpeed(speed);
}

//--------------------------------------------------------------
void ofApp::circleResolutionChanged(int& circleResolution) {
	ofSetCircleResolution(circleResolution);
}


//--------------------------------------------------------------
void ofApp::update() {
	ofSetCircleResolution(circleResolutionSnare);
	ofSetCircleResolution(circleResolutionBass);
	ofSetCircleResolution(circleResolutionHiTom);
	ofSetCircleResolution(circleResolutionCymbal);
}


//--------------------------------------------------------------
//--------------------------------------------------------------
void ofApp::draw() {
	ofBackgroundGradient(ofColor::white, ofColor::gray);

	// Draw snare drum
	if (filledSnare) {
		ofFill();
	}
	else {
		ofNoFill();
	}
	ofSetColor(colorSnare);
	ofDrawCircle(centerSnare, radiusSnare);
	// Draw text label for snare drum
	ofSetColor(0); // Set color to black for text
	ofDrawBitmapString("Snare", centerSnare->x - 20, centerSnare->y + 5);

	// Draw bass drum
	if (filledBass) {
		ofFill();
	}
	else {
		ofNoFill();
	}
	ofSetColor(colorBass);
	ofDrawCircle(centerBass, radiusBass);
	// Draw text label for bass drum
	ofSetColor(0); // Set color to black for text
	ofDrawBitmapString("Bass", centerBass->x - 17, centerBass->y + 5);

	// Draw hi-hat drum
	if (filledHiTom) {
		ofFill();
	}
	else {
		ofNoFill();
	}
	ofSetColor(colorHiTom);
	ofDrawCircle(centerHiTom, radiusHiTom);
	// Draw text label for hi-hat drum
	ofSetColor(0); // Set color to black for text
	ofDrawBitmapString("HiTom", centerHiTom->x - 20, centerHiTom->y + 5);

	// Draw cymbal drum
	if (filledCymbal) {
		ofFill();
	}
	else {
		ofNoFill();
	}
	ofSetColor(colorCymbal);
	ofDrawCircle(centerCymbal, radiusCymbal);
	// Draw text label for cymbal drum
	ofSetColor(0); // Set color to black for text
	ofDrawBitmapString("Cymbal", centerCymbal->x - 23, centerCymbal->y + 5);

	// Draw GUI
	if (!bHide) {
		gui.draw();
	}
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == 'h') {
		bHide = !bHide;
	}
	else if (key == 's') {
		gui.saveToFile("settings.xml");
	}
	else if (key == 'l') {
		gui.loadFromFile("settings.xml");
	}
	else if (key == ' ') {		//If space is pressed all things return to default
		colorSnare = ofColor(255);
		colorBass = ofColor(255);
		colorHiTom = ofColor(255);
		colorCymbal = ofColor(255);
		pitchSnare = 1.0;
		pitchBass = 1.0;
		pitchHiTom = 1.0;
		pitchCymbal = 1.0;
	}
	else if (key == OF_KEY_UP) { // Increase pitch

		snarePitch = pitchSnare;
		bassPitch = pitchBass;
		hiTomPitch = pitchHiTom;
		cymbalPitch = pitchCymbal;

		snarePitch += 0.1;
		bassPitch += 0.1;
		hiTomPitch += 0.1;
		cymbalPitch += 0.1;

		// Ensure pitch values stay within valid range
		pitchSnare = ofClamp(snarePitch, 0.5, 2.0);
		pitchBass = ofClamp(bassPitch, 0.5, 2.0);
		pitchHiTom = ofClamp(hiTomPitch, 0.5, 2.0);
		pitchCymbal = ofClamp(cymbalPitch, 0.5, 2.0);
	}
	else if (key == OF_KEY_DOWN) { // Decrease pitch
		snarePitch = pitchSnare;
		bassPitch = pitchBass;
		hiTomPitch = pitchHiTom;
		cymbalPitch = pitchCymbal;

		snarePitch -= 0.1;
		bassPitch -= 0.1;
		hiTomPitch -= 0.1;
		cymbalPitch -= 0.1;

		// Ensure pitch values stay within valid range
		pitchSnare = ofClamp(snarePitch, 0.5, 2.0);
		pitchBass = ofClamp(bassPitch, 0.5, 2.0);
		pitchHiTom = ofClamp(hiTomPitch, 0.5, 2.0);
		pitchCymbal = ofClamp(cymbalPitch, 0.5, 2.0);
	}



}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	// Calculate the distance between the mouse position and the center of the first circle
	float distToCircleSnare = ofDist(x, y, centerSnare->x, centerSnare->y);

	// Check if the mouse is within the first circle's radius
	if (distToCircleSnare < radiusSnare) {
		snare.setSpeed(pitchSnare);
		snare.play(); // Play the ring sound
	}

	// Calculate the distance between the mouse position and the center of the second circle
	float distToCircleBass = ofDist(x, y, centerBass->x, centerBass->y);

	// Check if the mouse is within the second circle's radius
	if (distToCircleBass < radiusBass) {
		bass.setSpeed(pitchBass);
		bass.play(); // Play the bass sound
	}

	float distToCircleHiTom = ofDist(x, y, centerHiTom->x, centerHiTom->y);
	if (distToCircleHiTom < radiusHiTom) {
		hiTom.setSpeed(pitchHiTom);
		hiTom.play(); // Play the hiTOm sound
	}

	float distToCircleCymbal = ofDist(x, y, centerCymbal->x, centerCymbal->y);
	if (distToCircleCymbal < radiusCymbal) {
		cymbal.setSpeed(pitchCymbal);
		cymbal.play(); // Play the cymbal sound
	}
}


//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {
	screenSize = ofToString(w) + "x" + ofToString(h);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
