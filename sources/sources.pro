TEMPLATE = subdirs
# It is necessary to build in exact order
CONFIG += ordered
SUBDIRS = host \
          core \
          gui \
          perf \
          proc \
          syminfo \
          app