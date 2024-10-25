#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/svrt_31/ardusub/blue_ws/src/bluerov_ros_playground"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/svrt_31/ardusub/blue_ws/install/lib/python3/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/svrt_31/ardusub/blue_ws/install/lib/python3/dist-packages:/home/svrt_31/ardusub/blue_ws/build/lib/python3/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/svrt_31/ardusub/blue_ws/build" \
    "/usr/bin/python3" \
    "/home/svrt_31/ardusub/blue_ws/src/bluerov_ros_playground/setup.py" \
     \
    build --build-base "/home/svrt_31/ardusub/blue_ws/build/bluerov_ros_playground" \
    install \
    --root="${DESTDIR-/}" \
    --install-layout=deb --prefix="/home/svrt_31/ardusub/blue_ws/install" --install-scripts="/home/svrt_31/ardusub/blue_ws/install/bin"
