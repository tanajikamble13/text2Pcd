#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>

int
  main (int argc, char** argv)
{
  pcl::PointCloud<pcl::PointXYZRGB> cloud;

  //ifstream inFile("filename.txt");
  //int i = 0;
  std::ifstream myFile;
  std::string line;
  int lines;
  myFile.open("sample.txt");
  for(lines = 0; std::getline(myFile,line); lines++);
  myFile.close();
  std::cout << "Point cloud size " << lines <<std::endl;
   // Fill in the cloud data
  cloud.width    = lines;
  cloud.height   = 1;
  cloud.is_dense = false;
  cloud.points.resize (cloud.width * cloud.height);
  int i=0;
  myFile.open("sample.txt");
  while (std::getline(myFile,line))
  { //std::cout << "In loop "<<std::endl;
    
    std::istringstream iss(line);
    if (!(iss >> cloud.points[i].x >> cloud.points[i].y >> cloud.points[i].z >> cloud.points[i].r >> cloud.points[i].g >> cloud.points[i].b)) { break; } // error
    /*
    if (i < lines-1)
    { 
   // myFile >> cloud.points[i].x >> cloud.points[i].y >> cloud.points[i].z >> cloud.points[i].r >> cloud.points[i].g >> cloud.points[i].b;
    std::cout << "red " <<cloud.points[i].r << " green " <<cloud.points[i].g << " blue " <<cloud.points[i].b <<std::endl;
    }
    i++;
   */
   std::cout << "red " <<cloud.points[i].r << " green " <<cloud.points[i].g << " blue " <<cloud.points[i].b <<std::endl;
   i++;
  }
  

  pcl::io::savePCDFileBinary("text2pcd.pcd", cloud);
  std::cerr << "Saved " << cloud.points.size () << " data points to test_pcd.pcd." << std::endl;

  for (size_t i = 0; i < cloud.points.size (); ++i)
    /*
   if (i %1000 == 0)
    {
    std::cerr << "    " << cloud.points[i].x << " " << cloud.points[i].y << " " << cloud.points[i].z << " "<< cloud.points[i].r << " " << cloud.points[i].g << " " << cloud.points[i].b << std::endl;
    }
 */
  myFile.close();
  return (0);
}
