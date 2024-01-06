# Line Follower Algorithm for Parrot Mini Drone

This repository presents a line follower algorithm developed for the Parrot mini drone. The algorithm, implemented using Simulink MATLAB, enables the drone to autonomously follow a red line with a landing circle at the end. The camera on the drone is utilized to detect the red line and circle, while the algorithm computes the necessary control inputs to keep the drone on track.

## Algorithm Overview

The line follower algorithm consists of two main components:

1. **Line Detection and Heading Calculation:** The live image from the drone's camera is processed to detect edges using the Canny filter. By applying the Hough line transform, the algorithm extracts the boundaries of the red line. The Hough line transform often results in multiple lines, so we select the two most prominent lines and calculate the average of their coordinates. This average coordinate represents a line that lies in the middle of the red line and provides an estimate of the drone's heading. However, in certain scenarios, such as approaching a turn, this method may encounter challenges due to the limited information from the first two lines. The algorithm can occasionally become confused about the heading when the blue line yields two possible directions with a 180° difference. To address this limitation, the algorithm incorporates additional techniques.

2. **Bitmap-based Approach for Heading Adjustment:** In this approach, the algorithm utilizes the bitmap of the red line during image processing. Two triangular-shaped regions of interest (ROIs) are created at the center of the image, with their orientations determined by the previous heading information. By calculating the intersection between the bitmap of the red line and the ROIs, the algorithm obtains a value that assists in deciding the next heading. Additionally, the algorithm generates two X-marks by averaging the bitmaps of the red line and the intersection of the ROIs. These X-marks contribute to flight stability and help maintain a consistent heading.

The algorithm also includes a landing feature. It employs the `imfindcircles()` function from MATLAB's Computer Vision Toolbox to locate the center of the landing circle. The drone initiates the landing process when the center of the circle falls within the defined ROI. This check ensures that the drone only lands when it reaches the intended target, preventing unnecessary landing decisions.

## Usage

To use this line follower algorithm with your Parrot mini drone, follow these steps:

1. Set up your Parrot mini drone and establish a connection with your computer.
2. Open the MATLAB project or script that contains the line follower algorithm.
3. Configure the relevant parameters, such as camera settings and ROI orientation, to match your drone setup.
4. Execute the script or run the simulation in Simulink to start the algorithm.
5. Monitor the drone's behavior as it follows the red line and lands on the designated circle.
6. Make adjustments to the algorithm or parameters as needed to improve performance based on your observations.

## Requirements

To run this line follower algorithm, you need the following:

- Parrot mini drone
- MATLAB with Simulink and Computer Vision Toolbox


<a href="https://youtu.be/0HNCLZ_FNcA" target="_blank"><img src="http://img.youtube.com/vi/BZZOMT-J5b0/0.jpg" 
alt="UAV Line Follower" width="240" height="180" border="10" /></a>
