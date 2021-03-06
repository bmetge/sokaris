//#include "cv.h"
//#include "highgui.h"
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/core/core.hpp>
//#include <opencv2/gpu/gpu.hpp>
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//using namespace cv;
//
//static CvMemStorage* storage = 0;
//static CvHaarClassifierCascade* cascade = 0;
//
//void detect_and_draw( IplImage* image );
//
//const char* cascade_name = "D:\\DEV\\lib\\opencv\\data\\haarcascades\\haarcascade_frontalface_alt.xml";
//
//int main( int argc, char** argv )
//{
//	CvCapture* capture = 0;
//	IplImage *frame, *frame_copy = 0;
//
//	cascade = (CvHaarClassifierCascade*)cvLoad( cascade_name, 0, 0, 0 );
//
//	if( !cascade )
//	{
//		fprintf( stderr, "ERROR: Could not load classifier cascade\n" );
//		//return -1;
//	}
//	storage = cvCreateMemStorage(0);
//
//	capture = cvCaptureFromCAM(0);
//	cvNamedWindow( "result", 1 );
//	for(;;)
//	{
//		if( !cvGrabFrame( capture ))
//			break;
//		frame = cvRetrieveFrame( capture );
//		if( !frame )
//			break;
//		if( !frame_copy )
//			frame_copy = cvCreateImage( cvSize(frame->width,frame->height),
//			IPL_DEPTH_8U, frame->nChannels );
//		if( frame->origin == IPL_ORIGIN_TL )
//			cvCopy( frame, frame_copy, 0 );
//		else
//			cvFlip( frame, frame_copy, 0 );
//
//		detect_and_draw( frame_copy );
//
//		if( cvWaitKey( 10 ) >= 0 )
//			break;
//	}
//	cvReleaseImage( &frame_copy );
//	cvReleaseCapture( &capture );
//
//	/* For a file .avi*/
//	/*capture = cvCaptureFromAVI( "demo.avi" ); 
//	cvNamedWindow( "result", 1 );
//	for(;;)
//	{
//		if( !cvGrabFrame( capture ))
//			break;
//		frame = cvRetrieveFrame( capture );
//		if( !frame )
//			break;
//		if( !frame_copy )
//			frame_copy = cvCreateImage( cvSize(frame->width,frame->height),
//			IPL_DEPTH_8U, frame->nChannels );
//		if( frame->origin == IPL_ORIGIN_TL )
//			cvCopy( frame, frame_copy, 0 );
//		else
//			cvFlip( frame, frame_copy, 0 );
//
//		detect_and_draw( frame_copy );
//
//		if( cvWaitKey( 10 ) >= 0 )
//			break;
//	}
//	cvReleaseImage( &frame_copy );
//	cvReleaseCapture( &capture );*/
//
//	
//	cvReleaseHaarClassifierCascade( &cascade );
//	cvDestroyWindow("result");
//
//return 0;
//}
//
//void detect_and_draw( IplImage* img )
//{
//	static CvScalar colors[] = 
//	{
//		{{0,0,255}},
//		{{0,128,255}},
//		{{0,255,255}},
//		{{0,255,0}},
//		{{255,128,0}},
//		{{255,255,0}},
//		{{255,0,0}},
//		{{255,0,255}}
//	};
//
//	double scale = 1.3;
//	IplImage* gray = cvCreateImage( cvSize(img->width,img->height), 8, 1 );
//	IplImage* small_img = cvCreateImage( cvSize( cvRound (img->width/scale),
//		cvRound (img->height/scale)),
//		8, 1 );
//	int i;
//
//	cvCvtColor( img, gray, CV_BGR2GRAY );
//	cvResize( gray, small_img, CV_INTER_LINEAR );
//	cvEqualizeHist( small_img, small_img );
//	cvClearMemStorage( storage );
//
//	if( cascade )
//	{
//		double t = (double)cvGetTickCount();
//		CvSeq* faces = cvHaarDetectObjects( small_img, cascade, storage,
//			1.1, 2, 0/*CV_HAAR_DO_CANNY_PRUNING*/,
//			cvSize(30, 30) );
//		t = (double)cvGetTickCount() - t;
//		printf( "detection time = %gms\n", t/((double)cvGetTickFrequency()*1000.) );
//		for( i = 0; i < (faces ? faces->total : 0); i++ )
//		{
//			CvRect* r = (CvRect*)cvGetSeqElem( faces, i );
//			CvPoint center;
//			int radius;
//			center.x = cvRound((r->x + r->width*0.5)*scale);
//			center.y = cvRound((r->y + r->height*0.5)*scale);
//			radius = cvRound((r->width + r->height)*0.25*scale);
//			cvCircle( img, center, radius, colors[i%8], 3, 8, 0 );
//		}
//	}
//
//	cvShowImage( "result", img );
//	cvReleaseImage( &gray );
//	cvReleaseImage( &small_img );
//}