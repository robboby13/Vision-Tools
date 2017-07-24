#include "opencv2/opencv.hpp"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio/videoio.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

using namespace std;
using namespace cv;

int main(){

    VideoCapture vcap1(002); 
    VideoCapture vcap2(004); 

      if(!vcap1.isOpened()){
             cout << "Error opening video stream or file" << endl;
             return -1;
      }
      if(!vcap2.isOpened()){
             cout << "Error opening video stream or file" << endl;
             return -1;
      }
  //namedWindow("Video Grabber", CV_WINDOW_AUTOSIZE); //Create a window called "Dura Rocks!"

   int frame_width1=   vcap1.get(CV_CAP_PROP_FRAME_WIDTH);
   int frame_height1=   vcap1.get(CV_CAP_PROP_FRAME_HEIGHT);

   int frame_width2=   vcap2.get(CV_CAP_PROP_FRAME_WIDTH);
   int frame_height2=   vcap2.get(CV_CAP_PROP_FRAME_HEIGHT);

//Initialize the video writter object
   VideoWriter video1("/media/dura/MyPassport/Camera Data/Side Camera Left/video1.avi",CV_FOURCC('M','J','P','G'),15, Size(frame_width1,frame_height1),true); 
   VideoWriter video2("/media/dura/MyPassport/Camera Data/Side Camera Right/video2.avi",CV_FOURCC('M','J','P','G'),15, Size(frame_width2,frame_height2),true); 


   cout << "Frame Size Camera 1 = " << frame_width1 << "x" << frame_height1 << endl;
   cout << "Frame Size Camera 2 = " << frame_width2 << "x" << frame_height2 << endl;

   int wow;
   Mat frame1;
   Mat frame2;
   
    for(;;){

       Mat frame1;
       vcap1 >> frame1;
       video1.write(frame1);
       imshow( "Camera 1", frame1 );
       char c = (char)waitKey(33);
       if( c == 27 ) break;
       else if(c == 0x20) {  //When you press the Spacebar
        
            vcap1 >> frame1; // get a new frame from camera    
            imshow("Your Image", frame1);
            imwrite("image.png", frame1);
       }
    
    for(;;){

       Mat frame2;
       vcap2 >> frame2;
       video2.write(frame2);
       imshow( "Camera 2", frame2 );
       char c = (char)waitKey(33);
       if( c == 27 ) break;
       else if(c == 0x20) {  //When you press the Spacebar
        
            vcap1 >> frame2; // get a new frame from camera    
            imshow("Your Image", frame2);
            imwrite("image.png", frame2);
       }


    }
   }
  return 0;
}
