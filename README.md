# SimpleScanpathAnalyser
An advanced approach for develop  simple scanpath analyser using C programming language

Autism Spectrum Disorder (ASD) is a neurodevelopmental disorder characterised by differences in communication and social interaction . Recent research studies have analysed the eye movements of people with and without autism recorded while interacting with web pages, and have found that people with autism tend to have different processing strategies in comparison with people without autism when they interact with web pages .

Eye tracking is the process of recording the eye movements of people to understand where they look at, called fixations, and how long these fixations last. The series of their fixations represent their scanpaths. Scanpaths are usually analysed based on the areas of interest (AOIs) of visual stimuli, especially which AOIs are frequently used and in which order. Figure 1 shows an example of a scanpath of a particular person on one web page of Wordpress.com where the red rectangles show the AOIs of the web page, and the yellow circles show the person’s fixations - the radius of each circle is directly proportional to the duration of its corresponding fixation.

![image](https://user-images.githubusercontent.com/90095338/220294960-4eea897b-08b6-4c2f-accf-2003dd1cfc39.png)


Keypoints: Algorithms, C language,  String Processing and Matching, Real Life Application for Autism, Pointers, Linked List





More Detailed Explanation:

To analyse scanpaths based on AOIs, they are first represented as string sequences. For example, if a person looks at the AOIs L, M, P, and R respectively, his/her scanpath is represented as LMPR. In this assignment, you will need to develop another simple scanpath analyser to check whether a given pattern is available in a set of scanpaths of people with and without autism.

This application will start by taking the name of the two files from the user where the first file includes a number of scanpaths for people with autism and another one includes a number of scanpaths for people without autism, which are represented as string sequences based on ten AOIs named with digits from zero to 9. These files may include a different number of scanpaths, and each line in these files represent a different scanpath.

You can assume that the maximum length of a scanpath is 100. An example content of a file is given below:
6547382712384758123
3547712364687
847364537292
9374638473682


