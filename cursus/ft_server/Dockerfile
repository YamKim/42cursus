FROM	debian:buster

LABEL	maintainer="yekim@student.42seoul.kr"

RUN		mkdir /ft_server 
RUN		apt-get update && apt-get upgrade -y
RUN		apt-get install -y nginx 
RUN		apt-get install -y curl 
RUN		apt-get install -y wget 
RUN		apt-get install -y openssl 
RUN		apt-get install -y mariadb-server 
RUN		apt-get install -y php-mysql 
RUN		apt-get install -y php-mbstring 
RUN		apt-get install -y php7.3-fpm 
RUN		apt-get install -y php-curl

COPY	./srcs/run.sh ./
COPY	./srcs/default ./ft_server
COPY	./srcs/wp-config.php ./ft_server
COPY	./srcs/config.inc.php ./ft_server

EXPOSE	80
EXPOSE	443

CMD		bash ./run.sh
