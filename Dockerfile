FROM ubuntu:trusty

SHELL ["/bin/bash", "-c"]
RUN rm /bin/sh && ln -s /bin/bash /bin/sh
WORKDIR /keyplus

# Install setup script dependencies
RUN apt-get update && apt-get install -y wget git unzip python3 python3-pip
RUN pip3 install --user -U setuptools
RUN ln -s /usr/bin/python3 /usr/bin/python
# Add files that the setup script expects without invalidating the entire cache
# Trick setup script into not installing submodules yet
RUN git init .
ADD env/ubuntu-14.04-setup.sh /keyplus/env/ubuntu-14.04-setup.sh
ADD host-software/keyplus/version.py /keyplus/host-software/keyplus/version.py
# Install keyplus environment
RUN cd /keyplus/env && bash ubuntu-14.04-setup.sh
RUN echo "source /keyplus/env/enter_env.sh" >> ~/.bashrc
# Remove dummy git repo
RUN rm -rf .git

ADD . /keyplus
RUN git submodule update --init --recursive