#!/usr/bin/env python3
import rclpy
import cv2
import numpy as np
from rclpy.node import  Node
import threading
import time
class Cnn(Node):

     def __init__(self):
        super().__init__("Image_processing")
        z1=time.perf_counter()
        
        
        
        
        
        
        
        
        
        z2=time.perf_counter()
        t=z2-z1

def main(args=None):
    rclpy.init(args=args)  
    node=Cnn()

    rclpy.spin(node)
    rclpy.shutdown()

if __name__=="__main__":
    main()