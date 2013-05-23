//
//  Camera.h
//  sokaris
//
//  Created by Clément Garnier on 06/05/13.
//  Copyright (c) 2013 AKH Partners. All rights reserved.
//

#ifndef __sokaris__Camera__
#define __sokaris__Camera__

#include <iostream>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

namespace sokaris
{
	class Camera
    {
    private :
		int id;						// Identification unique pour chaque caméra
        Point3d position;			// Coordonnées de la caméra, avec Hauteur de la caméra
        vector<float> angles;       // Angle de vue de la caméra
        int framerate;              // Nombre d'image par seconde
		string format;
		float timestamp;
        
    public:
        Camera(void);
        Camera(int id, Point3d position, float angleX, float angleY, 
			float angleZ, int framerate, string format, float timestamp);
        ~Camera(void);
        
        int getId();
		Point3d getPosition();
		vector<float> getAngles();
		int getFramerate();
		string getFormat();
		float getTimestamp();

        void setPosition(Point3d point);
		void setAngles(vector<float> a);

    };
}

#endif /* defined(__sokaris__Camera__) */
