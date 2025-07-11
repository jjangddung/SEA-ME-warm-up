cmake_minimum_required(VERSION 3.19)
project(RacingCAR LANGUAGES CXX)

# Qt6 필수 모듈 불러오기
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Gui)

qt_standard_project_setup()

# ✅ Qt6 리소스 등록 (.qrc → .cpp 자동 생성)
#qt6_add_resources(GENERATED_RESOURCES final.qrc)
qt6_add_resources(GENERATED_RESOURCES test.qrc)

# 실행 파일 빌드
qt_add_executable(RacingCAR
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    car.h car.cpp
    control.h control.cpp
    obstacle.h obstacle.cpp
    gamewidget.h gamewidget.cpp
    gamelogicthread.h gamelogicthread.cpp

    ${GENERATED_RESOURCES}
    game_start.h game_start.cpp game_start.ui





    #test.qrc    # ✅ 리소스 cpp 포함
)

# Qt 라이브러리 연결
target_link_libraries(RacingCAR
    PRIVATE
        Qt6::Core
        Qt6::Widgets
        Qt6::Gui
)

# 설치 경로 지정
include(GNUInstallDirs)

install(TARGETS RacingCAR
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

# 배포 스크립트 생성
qt_generate_deploy_app_script(
    TARGET RacingCAR
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)

install(SCRIPT ${deploy_script})
