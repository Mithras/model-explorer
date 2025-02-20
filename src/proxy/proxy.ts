import type { RequestOptions } from "node:https";

import * as proxy from "express-http-proxy";
import * as express from "express";

var app = express();
app.use(
  // Replace with 'http://host.docker.internal:8080/' on Mac/Windows
  proxy("http://localhost:8080/", {
    proxyReqOptDecorator: function (proxyReqOpts: RequestOptions, originalReq) {
      proxyReqOpts.rejectUnauthorized = false;
      return proxyReqOpts;
    },
    filter: function (req, res) {
      return new Promise(function (resolve) {
        resolve(req.url.startsWith("/api"));
      });
    },
  })
);
app.use(proxy("http://localhost:4200/"));

const port = 3000;
app.listen(port, () => {
  console.log(`Listening on port ${port}`);
});
