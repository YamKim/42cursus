FROM alpine:3.12

RUN apk update
	
RUN apk add nginx
RUN	mkdir -p /run/nginx
	#touch /var/run/nginx/nginx.pid && \
RUN apk add php7 php7-fpm php7-opcache php7-gd php7-mysqli \
	php7-zlib php7-curl php7-mbstring php7-json php7-session

RUN rm -rf /var/cache/apk/*

WORKDIR /tmp/
COPY ./srcs/phpMyAdmin-5.0.2-all-languages.tar.gz ./
RUN tar zxvf phpMyAdmin-5.0.2-all-languages.tar.gz
RUN rm phpMyAdmin-5.0.2-all-languages.tar.gz
RUN mv phpMyAdmin-5.0.2-all-languages phpmyadmin
RUN mv phpmyadmin /var/www/phpmyadmin

COPY ./srcs/nginx.conf /etc/nginx/nginx.conf
COPY ./srcs/config.inc.php /var/www/phpmyadmin/
COPY ./srcs/run.sh /usr/sbin/

RUN chmod +x /usr/sbin/run.sh

EXPOSE 5000

ENTRYPOINT ["sh", "/usr/sbin/run.sh"]
