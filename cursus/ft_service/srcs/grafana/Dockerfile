FROM alpine:3.12

RUN apk update

# grafana setting
RUN apk --no-cache add libc6-compat;
COPY ./srcs/grafana-7.4.3.linux-amd64.tar.gz ./
RUN tar -zxvf grafana-7.4.3.linux-amd64.tar.gz
RUN mv grafana-7.4.3 /usr/share/grafana
RUN mkdir -p /var/lib/grafana/dashboards

# telegraf setting
COPY ./srcs/telegraf-1.14.0-static_linux_amd64.tar.gz ./
RUN tar zxvf telegraf-1.14.0-static_linux_amd64.tar.gz
RUN mv telegraf-1.14.0-static_linux_amd64.tar.gz telegraf
RUN mv telegraf /usr/sbin
COPY ./srcs/telegraf.conf /usr/sbin/telegraf/
ENV TELEGRAF_CONFIG_PATH /usr/sbin/telegraf/telegraf.conf

# configuration setting
RUN rm -rf /var/cache/apk/*
COPY ./srcs/dashboards /var/lib/grafana/dashboards/
COPY ./srcs/config/influxdb.yaml /usr/share/grafana/conf/provisioning/datasources/
COPY ./srcs/config/dashboards.yaml /usr/share/grafana/conf/provisioning/dashboards/

# run setting
COPY ./srcs/run.sh /usr/sbin/
RUN chmod +x /usr/sbin/run.sh

EXPOSE 3000

ENTRYPOINT ["sh", "/usr/sbin/run.sh"]
