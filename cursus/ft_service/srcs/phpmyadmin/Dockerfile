FROM alpine:3.12

RUN apk update

# nginx setting
RUN apk add nginx
RUN	mkdir -p /run/nginx

# php setting
RUN apk add php7 php7-fpm php7-opcache php7-gd php7-mysqli \
	php7-zlib php7-curl php7-mbstring php7-json php7-session

WORKDIR /tmp/
# pma setting
COPY ./srcs/phpMyAdmin-5.0.2-all-languages.tar.gz ./
RUN tar zxvf phpMyAdmin-5.0.2-all-languages.tar.gz
RUN rm phpMyAdmin-5.0.2-all-languages.tar.gz
RUN mv phpMyAdmin-5.0.2-all-languages phpmyadmin
RUN mv phpmyadmin /var/www/

# telegraf setting
COPY ./srcs/telegraf-1.14.0-static_linux_amd64.tar.gz ./
RUN tar zxvf telegraf-1.14.0-static_linux_amd64.tar.gz
RUN mv telegraf-1.14.0-static_linux_amd64.tar.gz telegraf
RUN mv telegraf /usr/sbin
COPY ./srcs/telegraf.conf /usr/sbin/telegraf/
ENV TELEGRAF_CONFIG_PATH /usr/sbin/telegraf/telegraf.conf

# configuration setting
COPY ./srcs/nginx.conf /etc/nginx/
COPY ./srcs/config.inc.php /var/www/phpmyadmin/
RUN rm -rf /var/cache/apk/*

# run setting
COPY ./srcs/run.sh /usr/sbin/
RUN chmod +x /usr/sbin/run.sh

EXPOSE 5000

ENTRYPOINT ["sh", "/usr/sbin/run.sh"]
