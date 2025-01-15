# ?data={"models":[{"url":"/workspace/coco-ssd.tflite.json","adapterId":"builtin_json"},{"url":"/workspace/coco-ssd-tf.json","adapterId":"builtin_json"}]}

function model-explorer-pckg {
  pushd ~/model-explorer-pckg
  source venv/bin/activate

  model-explorer
  # --no_open_in_browser

  deactivate
  popd
}

function model-explorer-ui-init {
  pushd /workspace/src/ui
  npm install
  popd
}

function model-explorer-ui {
  pushd /workspace/src/ui
  
  ng serve --host 0.0.0.0
  # --serve-path ...

  popd
}

function model-explorer-ui-build {
  pushd /workspace/src/ui
  
  ng build --base-href /intern/mlhub/model_explorer/ --deploy-url /intern/mlhub/model_explorer/
  rm -rf dist/model_explorer/browser/static_files/*.woff2
  
  popd
}

function model-explorer-server-init {
  pushd /workspace/src/server
  python3 -m venv venv
  source venv/bin/activate

  ./scripts/setup_local_dev.sh
  
  deactivate
  popd
}

function proxy {
  pushd /workspace/src/proxy

  npm run proxy
  
  popd
}
