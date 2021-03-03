FROM alpine:3.12

RUN apk update
RUN apk add nginx
RUN apk add php7 php7-fpm php7-opcache
RUN apk add lighttpd php7-common php7-iconv php7-json php7-gd php7-curl php7-xml \
	php7-mysqli php7-imap php7-cgi fcgi php7-pdo php7-pdo_mysql php7-soap php7-xmlrpc \
	php7-posix php7-mcrypt php7-gettext php7-ldap php7-ctype php7-dom
#RUN wget https://files.phpmyadmin.net/phpMyAdmin/4.9.0.1/phpMyAdmin-4.9.0.1-all-languages.tar.gz
#RUN tar -xvf phpMyAdmin-4.9.0.1-all-languages.tar.gz
#
#RUN mv phpMyAdmin-4.9.0.1-all-languages phpmyadmin
#RUN rm -rf /var/cache/apk/*

#RUN mkdir -p /usr/share/webapps/
#RUN cd /usr/share/webapps
RUN wget http://files.directadmin.com/services/all/phpMyAdmin/phpMyAdmin-5.0.2-all-languages.tar.gz
RUN tar zxvf phpMyAdmin-5.0.2-all-languages.tar.gz

RUN rm phpMyAdmin-5.0.2-all-languages.tar.gz
RUN mv phpMyAdmin-5.0.2-all-languages phpmyadmin
#RUN chmod -R 777 /usr/share/webapps/
RUN mv /phpmyadmin /var/www/

COPY srcs/default.conf /etc/nginx/conf.d/default.conf
COPY srcs/config.inc.php /var/www/phpmyadmin/
COPY srcs/run.sh /usr/sbin/

RUN chmod +x /usr/sbin/run.sh

EXPOSE 5000

ENTRYPOINT ["/usr/sbin/run.sh"]
