import React from "react";
import { connect } from "react-redux";

import B1 from "./B1";

function BoardRows({ size }) {
  let rows = [];
  let i = 1;

  for (i; i <= size; i++) {
    rows.push({
      key: i,
      rowIndex: i,
      size
    });
  }

  return (
    <React.Fragment>
      {rows.map(options => (
        <B1 {...options} />
      ))}
    </React.Fragment>
  );
}

const mapStateToProps = state => ({
  size: state.game.size
});

export default connect(mapStateToProps)(BoardRows);
