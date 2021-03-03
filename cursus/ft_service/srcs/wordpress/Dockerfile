FROM alpine:3.12

RUN apk update

# nginx setting
RUN apk add nginx mysql-client
RUN	mkdir -p /run/nginx

# php setting
RUN apk add php7 php7-fpm php7-opcache php7-gd php7-mysqli \
	php7-zlib php7-curl php7-mbstring php7-json php7-session

# wordpress setting
WORKDIR /tmp/
COPY ./srcs/wordpress-5.6.1.tar.gz ./
RUN tar zxvf wordpress-5.6.1.tar.gz
RUN rm wordpress-5.6.1.tar.gz
RUN mv wordpress /var/www/

# telegraf setting
COPY ./srcs/telegraf-1.14.0-static_linux_amd64.tar.gz ./
RUN tar zxvf telegraf-1.14.0-static_linux_amd64.tar.gz
RUN mv telegraf-1.14.0-static_linux_amd64.tar.gz telegraf
RUN mv telegraf /usr/sbin
COPY ./srcs/telegraf.conf /usr/sbin/telegraf/
ENV TELEGRAF_CONFIG_PATH /usr/sbin/telegraf/telegraf.conf

# configuration setting
COPY ./srcs/wordpress.sql ./
COPY ./srcs/nginx.conf /etc/nginx/
COPY ./srcs/wp-config.php /var/www/wordpress/
COPY ./srcs/set_wpdb.sh ./

# run setting
COPY ./srcs/run.sh /usr/sbin/
RUN chmod +x /tmp/set_wpdb.sh
RUN chmod +x /usr/sbin/run.sh
RUN rm -rf /var/cache/apk/*

EXPOSE 5050

ENTRYPOINT ["sh", "/usr/sbin/run.sh"]
