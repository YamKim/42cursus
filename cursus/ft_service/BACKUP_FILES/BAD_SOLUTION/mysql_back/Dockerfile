FROM alpine:3.12

RUN apk update && apk upgrade
RUN apk add mysql mysql-client
RUN rm -rf /var/cache/apk/*

COPY ./srcs/mariadb-server.cnf /etc/my.cnf.d/
#COPY ./srcs/init_db.sql /tmp/
COPY ./srcs/run.sh /usr/sbin/

RUN chmod +x /usr/sbin/run.sh

EXPOSE 3306

ENTRYPOINT ["/usr/sbin/run.sh"]
