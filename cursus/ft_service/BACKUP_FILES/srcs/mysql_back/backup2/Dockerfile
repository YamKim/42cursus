FROM alpine:3.12

RUN apk update
RUN apk add mariadb
RUN apk add mariadb-client
RUN rm -rf /var/cache/apk/*

#RUN mkdir -p /run/mysqld
#RUN service mysql start

#COPY srcs/my.cnf /etc/mysql/my.conf
#COPY srcs/mysql-init /tmp/mysql-init
#COPY srcs/start.sh /tmp/start.sh
COPY srcs/db_template.sql /tmp/
COPY srcs/run_mysql.sh /tmp/
COPY srcs/run.sh /usr/sbin/

#RUN	rm -rf /etc/my.cnf*
#COPY srcs/my.cnf /etc/mysql/
RUN	mkdir -p /var/lib/mysql /run/mysqld

#RUN service mysql start && mysql -u root < /tmp/mysql-init
RUN chmod +x /usr/sbin/run.sh

EXPOSE 3306

ENTRYPOINT ["/usr/sbin/run.sh"]
