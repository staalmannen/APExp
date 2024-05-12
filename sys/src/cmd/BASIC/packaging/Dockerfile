# ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#
# Works with Alpine Linux 3.18. Enter the BaCon source directory and create the Docker image with:
#
#   $ cp packaging/Dockerfile .
#   $ docker build -t bacon .
#
# Run the BaCon converter as follows:
#
#   $ docker run --rm --volume $(pwd):/tmp bacon myapp.bac
#
# Or run the BaCon converter as follows when you have some other user ID / group ID:
#
#   $ docker run --rm --volume $(pwd):/tmp --user "$(id -u):$(id -g)" bacon myapp.bac
#
# ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

FROM alpine:latest

RUN apk update
RUN apk add build-base musl-fts-dev zsh flex indent openssl-libs-static openssl-dev pcre-dev

COPY . /usr/src/bacon
WORKDIR /usr/src/bacon

ENV BACON_IN_DOCKER=true

RUN ./configure --disable-gui
RUN make
RUN make install

RUN rm -rf /var/cache/apk/*

WORKDIR /tmp

ENV HOME="/tmp"

# Default user on most Linux versions
USER 1000:1000

ENTRYPOINT [ "bacon", "-l", "-static" ]

CMD [ "-h" ]
