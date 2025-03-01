FROM ubuntu

WORKDIR /tmp

# Install extra packages
RUN apt-get update \
  && apt-get install -y openssh-client nano sudo curl git python3.12-venv

# Install node, npm and @angular/cli
RUN curl -fsSL https://deb.nodesource.com/setup_23.x -o nodesource_setup.sh \
  && sudo -E bash nodesource_setup.sh \
  && sudo apt-get install -y nodejs \
  && sudo npm install -g npm \
  && sudo npm install -g @angular/cli esbuild

# Change existing user
ARG USERNAME=ubuntu
ARG USER_UID=1000
ARG USER_GID=$USER_UID
RUN groupmod --gid $USER_GID $USERNAME \
    && usermod --uid $USER_UID --gid $USER_GID $USERNAME \
    && chown -R $USER_UID:$USER_GID /home/$USERNAME \
    && echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME \
    && chmod 0440 /etc/sudoers.d/$USERNAME

USER $USERNAME

# Install model-explorer package
RUN mkdir -p ~/model-explorer-pckg \
  && cd ~/model-explorer-pckg \
  && python3.12 -m venv venv \
  && . venv/bin/activate \
  && pip install torch ai-edge-model-explorer \
    --index-url https://download.pytorch.org/whl/cpu \
    --extra-index-url https://pypi.python.org/simple

# Setup .bashrc
RUN ln -sf /workspace/.devcontainer/.bashrc ~

WORKDIR /workspace

# docker compose build dev
# docker compose run -it --rm dev
