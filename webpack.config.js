const path = require('path');

module.exports = {
  entry: {
    main: './lib/js/re/index.js',
    slider: './lib/js/re/slider.js',
  },
  module: {
    rules: [
      {
        test: /\.js$/,
        loader: 'babel-loader',
        exclude: /node_modules/,
      },
    ],
  },
};
