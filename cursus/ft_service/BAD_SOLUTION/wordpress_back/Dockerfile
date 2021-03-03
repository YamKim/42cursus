FROM alpine:3.12

RUN apk update
RUN apk add php7 php7-fpm php7-opcache
RUN apk add php7-zlib php7-gd php7-mysqli
RUN apk add php7-curl php7-mbstring php7-json php7-session

RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xvf latest.tar.gz
RUN rm -f latest.tar.gz

RUN rm -rf /var/cache/apk/*

COPY srcs/wp-config.php /wp-config.php
COPY srcs/start.sh /usr/sbin/start.sh

RUN chmod +x /usr/sbin/start.sh

EXPOSE 5050

ENTRYPOINT ["/usr/sbin/start.sh"]
