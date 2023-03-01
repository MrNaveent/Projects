import React from "react";
import { Provider } from "react-redux";
import createSagaMiddleware from "redux-saga"

import configureStore from "./shop/main2";
import GameArea from "./frame/GameArea";
import main from "./redux s/main"

const sagaMiddleware = createSagaMiddleware()
const store = configureStore(sagaMiddleware)
sagaMiddleware.run(main)

function App() {
  return (
    <Provider store={store}>
      <GameArea />
    </Provider>
  );
}

export default App;
