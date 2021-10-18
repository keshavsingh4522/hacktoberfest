import { Fragment } from "react";

const InputComponent = (props) => {
  const { value, setValue, label, type = "text", placeHolder } = props;

  return (
    <Fragment>
      <p className="my-4">{label}</p>
      <input
        className="input"
        type={type}
        placeholder={placeHolder}
        value={value}
        onChange={(e) => setValue(e.target.value)}
      />
    </Fragment>
  );
};

export default InputComponent;
