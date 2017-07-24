#include "opencv2/opencv.hpp"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio/videoio.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

int main(){

    VideoCapture vcap1(5); 

      if(!vcap1.isOpened()){
             cout << "Error opening video stream or file" << endl;
             return -1;
      }

  //namedWindow("Video Grabber", CV_WINDOW_AUTOSIZE); //Create a window called "Dura Rocks!"

   int frame_width=   vcap1.get(CV_CAP_PROP_FRAME_WIDTH);
   int frame_height=   vcap1.get(CV_CAP_PROP_FRAME_HEIGHT);

//Initialize the video writter object
   VideoWriter video1("/media/dura/MyPassport/Camera Data/video.avi",CV_FOURCC('M','J','P','G'),15, Size(frame_width,frame_height),true); 


   cout << "Frame Size = " << frame_width << "x" << frame_height << endl;

   int wow;
   Mat frame;
   
    for(;;){

       Mat frame;
       vcap1 >> frame;
       video1.write(frame);
       imshow( "Dura Automotive Systems", frame );
       char c = (char)waitKey(33);
       if( c == 27 ) break;
       else if(c == 0x20) {  //When you press the Spacebar
        
            vcap1 >> frame; // get a new frame from camera    
            imshow("Your Image", frame);
            imwrite("image.png", frame);
       }
    }

  return 0;
}
