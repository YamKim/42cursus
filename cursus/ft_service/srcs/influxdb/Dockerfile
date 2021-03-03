FROM alpine:3.12

RUN apk update

# influxdb setting
RUN apk add influxdb

# telegraf setting
COPY ./srcs/telegraf-1.14.0-static_linux_amd64.tar.gz ./
RUN tar zxvf telegraf-1.14.0-static_linux_amd64.tar.gz
RUN mv telegraf-1.14.0-static_linux_amd64.tar.gz telegraf
RUN mv telegraf /usr/sbin
COPY ./srcs/telegraf.conf /usr/sbin/telegraf/
ENV TELEGRAF_CONFIG_PATH /usr/sbin/telegraf/telegraf.conf

# configuration setting
COPY ./srcs/influxdb.conf /etc/influxdb.conf
RUN rm -rf /var/cache/apk/*

# run setting
COPY ./srcs/run.sh /usr/sbin/
RUN chmod +x /usr/sbin/run.sh

EXPOSE 8086

ENTRYPOINT ["/usr/sbin/run.sh"]
