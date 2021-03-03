FROM alpine:3.12

RUN apk update

# nginx setting
RUN mkdir -p /run/nginx
RUN	apk add nginx
RUN apk add openssl 
RUN apk add openssh 
RUN rm -rf /var/cache/apk/*

# telegraf setting
COPY ./srcs/telegraf-1.14.0-static_linux_amd64.tar.gz ./
RUN tar zxvf telegraf-1.14.0-static_linux_amd64.tar.gz
RUN mv telegraf-1.14.0-static_linux_amd64.tar.gz telegraf
RUN mv telegraf /usr/sbin
COPY ./srcs/telegraf.conf /usr/sbin/telegraf/
ENV TELEGRAF_CONFIG_PATH /usr/sbin/telegraf/telegraf.conf

# configuration setting
COPY ./srcs/default.conf /etc/nginx/conf.d/
COPY ./srcs/index.html /var/www/
COPY ./srcs/sshd_config /etc/ssh/

# run setting
COPY ./srcs/run.sh /usr/sbin/
RUN chmod +x /usr/sbin/run.sh

EXPOSE 80 443 22

ENTRYPOINT ["sh", "/usr/sbin/run.sh"]
