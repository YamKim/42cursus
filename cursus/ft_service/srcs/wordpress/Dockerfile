FROM alpine:3.12

RUN apk update
RUN apk add nginx mysql-client
RUN	mkdir -p /run/nginx

RUN apk add php7 php7-fpm php7-opcache php7-gd php7-mysqli \
	php7-zlib php7-curl php7-mbstring php7-json php7-session

RUN rm -rf /var/cache/apk/*

WORKDIR /tmp/
COPY ./srcs/wordpress-5.6.1.tar.gz ./
RUN tar zxvf wordpress-5.6.1.tar.gz
RUN rm wordpress-5.6.1.tar.gz
RUN mv wordpress /var/www/

COPY ./srcs/nginx.conf /etc/nginx/
COPY ./srcs/wp-config.php /var/www/wordpress/

COPY ./srcs/wordpress.sql ./
COPY ./srcs/set_wpdb.sh ./

COPY ./srcs/run.sh /usr/sbin/
RUN chmod +x /tmp/set_wpdb.sh
RUN chmod +x /usr/sbin/run.sh

EXPOSE 5050

ENTRYPOINT ["sh", "/usr/sbin/run.sh"]
