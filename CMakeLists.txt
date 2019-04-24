project(phonon_tester)
cmake_minimum_required(VERSION 3.14.3 FATAL_ERROR)
set(QT_MIN_VERSION "5.12.0")
set(KF5_MIN_VERSION "5.57.0")
find_package(ECM 5.57.0 REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${ECM_KDE_MODULE_DIR})

include(KDEInstallDirs)
include(KDECompilerSettings NO_POLICY_SCOPE)
include(KDECMakeSettings)
include(FeatureSummary)

find_package(Qt5 ${QT_MIN_VERSION} CONFIG REQUIRED COMPONENTS
    Core
    Widgets
)

find_package(KF5 ${KF5_MIN_VERSION} REQUIRED COMPONENTS
    CoreAddons
    Completion
    I18n
    XmlGui
)

find_package(Phonon4Qt5 4.10.2 REQUIRED NO_MODULE)
include_directories(BEFORE ${PHONON_INCLUDES})

feature_summary(WHAT ALL INCLUDE_QUIET_PACKAGES FATAL_ON_MISSING_REQUIRED_PACKAGES)

set(phonon_tester_SRCS main.cpp mainwindow.cpp)

add_executable(phonon_tester ${phonon_tester_SRCS})

target_link_libraries(phonon_tester
  Qt5::Widgets
  KF5::CoreAddons
  KF5::Completion
  KF5::I18n
  KF5::XmlGui
  ${PHONON_LIBRARY})
