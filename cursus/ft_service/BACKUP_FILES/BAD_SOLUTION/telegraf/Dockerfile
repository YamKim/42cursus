FROM alpine:3.12

RUN apk update

COPY ./srcs/telegraf-1.14.0-static_linux_amd64.tar.gz ./
RUN tar zxvf telegraf-1.14.0-static_linux_amd64.tar.gz
RUN mv telegraf-1.14.0-static_linux_amd64.tar.gz telegraf
RUN mv telegraf /usr/sbin

COPY ./srcs/telegraf.conf /usr/sbin/telegraf/

RUN chmod +x /usr/sbin/telegraf

ENV TELEGRAF_CONFIG_PATH /usr/sbin/telegraf/telegraf.conf

#ENTRYPOINT ["/usr/sbin/telegraf/telegraf"]
