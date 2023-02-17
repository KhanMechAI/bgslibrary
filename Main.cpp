/*
This file is part of BGSLibrary.

BGSLibrary is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

BGSLibrary is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with BGSLibrary.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "Config.h"
#include "VideoAnalysis.h"
#include <iostream>

namespace bgslibrary
{
  class Main
  {
  private:
    Main();

  public:
    static void start(int argc, const char **argv)
    {
      std::cout << "---------------------------------------------" << std::endl;
      std::cout << "Background Subtraction Library               " << std::endl;
      std::cout << "https://github.com/andrewssobral/bgslibrary  " << std::endl;
      std::cout << "by:                                          " << std::endl;
      std::cout << "Andrews Sobral (andrewssobral@gmail.com)     " << std::endl;
      std::cout << "---------------------------------------------" << std::endl;
      std::cout << "Using OpenCV version " << CV_VERSION << std::endl;

      try
      {
        auto key = KEY_ESC;

        do
        {
          auto videoAnalysis = std::make_unique<VideoAnalysis>();

          if (videoAnalysis->setup(argc, argv))
          {
            videoAnalysis->start();

            std::cout << "Processing finished, enter:" << std::endl;
            std::cout << "R - Repeat" << std::endl;
            std::cout << "Q - Quit" << std::endl;

            key = cv::waitKey();
          }

          cv::destroyAllWindows();

        } while (key == KEY_REPEAT);
      }
      catch (const std::exception& ex)
      {
        std::cout << "std::exception:" << ex.what() << std::endl;
        return;
      }
      catch (...)
      {
        std::cout << "Unknow error" << std::endl;
        return;
      }

#ifdef WIN32
      //system("pause");
#endif
    }
  };
}

int main(int argc, const char **argv)
{
  bgslibrary::Main::start(argc, argv);
  return 0;
}
