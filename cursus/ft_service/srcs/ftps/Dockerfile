FROM alpine:3.12

# ftps setting
RUN apk add vsftpd

# telegraf setting
COPY ./srcs/telegraf-1.14.0-static_linux_amd64.tar.gz ./
RUN tar zxvf telegraf-1.14.0-static_linux_amd64.tar.gz
RUN mv telegraf-1.14.0-static_linux_amd64.tar.gz telegraf
RUN mv telegraf /usr/sbin
COPY ./srcs/telegraf.conf /usr/sbin/telegraf/
ENV TELEGRAF_CONFIG_PATH /usr/sbin/telegraf/telegraf.conf

# configuration setting
COPY ./srcs/ssl/vsftpd.crt /etc/ssl/
COPY ./srcs/ssl/vsftpd.key /etc/ssl/
COPY ./srcs/vsftpd.conf /etc/vsftpd/
COPY ./srcs/run.sh /usr/sbin/
RUN rm -rf /var/cache/apk/* 

EXPOSE 20 21 21100-21104

# run setting
RUN chmod +x /usr/sbin/run.sh

ENTRYPOINT ["sh", "/usr/sbin/run.sh"]
