FROM alpine:3.12

RUN apk add vsftpd
RUN rm -rf /var/cache/apk/* 

COPY ./srcs/ssl/vsftpd.crt /etc/ssl/
COPY ./srcs/ssl/vsftpd.key /etc/ssl/

COPY ./srcs/vsftpd.conf /etc/vsftpd/
COPY ./srcs/run.sh /usr/sbin/

EXPOSE 20 21 21100-21104

RUN chmod +x /usr/sbin/run.sh

ENTRYPOINT ["sh", "/usr/sbin/run.sh"]
