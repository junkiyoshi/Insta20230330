#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(0);
	ofSetColor(255);
	ofSetLineWidth(1.5);
	ofNoFill();
	ofSetRectMode(ofRectMode::OF_RECTMODE_CENTER);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	auto span = 20;
	for (int x = 0; x <= 720; x += span) {

		for (int y = 0; y <= 720; y += span) {

			ofPushMatrix();
			ofTranslate(x, y);

			auto noise_y = ofMap(ofNoise(x * 0.0025 + ofGetFrameNum() * 0.01), 0, 1, 0, 720);

			int deg_x = ofRandom(360) + ofGetFrameNum() * ofRandom(0.5, 0.85);
			int deg_y = ofRandom(360) + ofGetFrameNum() * ofRandom(0.5, 0.85);
			int deg_z = ofRandom(360) + ofGetFrameNum() * ofRandom(0.5, 0.85);

			deg_x = deg_x % 360;
			deg_y = deg_y % 360;
			deg_z = deg_z % 360;

			auto distance = abs(y - noise_y);
			auto power = 1.f;
			if (distance < span * 6) {

				if (distance > span * 4) {
				
					power = ofMap(distance, span * 4, span * 6, 1, 0);
				}

				ofRotateZ(deg_z * power);
				ofRotateY(deg_y * power);
				ofRotateX(deg_x * power);
			}

			ofFill();
			ofSetColor(255);
			ofDrawRectangle(0, 0, span, span);

			ofNoFill();
			ofSetColor(0);
			ofDrawRectangle(0, 0, span, span);

			ofPopMatrix();
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}