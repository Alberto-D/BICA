cmake_minimum_required(VERSION 2.8.3)
project(bica_rqt_graph)
# Load catkin and all dependencies required for this package
find_package(catkin REQUIRED)
catkin_package()
catkin_python_setup()


install(FILES plugin.xml
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

install(DIRECTORY resource
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

install(PROGRAMS scripts/bica_rqt_graph
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
