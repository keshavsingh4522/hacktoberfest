import React from "react";

interface Props {
    open: boolean;
    children: React.ReactNode;
    slide: "left" | "right"
    close: () => void;
}

export default function SlideOver({ open, children, close, slide }: Props) {
    const startPositionClass: string = slide == "left" ? " inset-0" : " right-0"
    const marginClass: string = slide == "left" ? " -ml-72" : " -mr-72"

    return (
        <>
            {open == true ? (
                <div
                    onClick={() => close()}
                    className="fixed inset-0 z-[90] h-screen w-screen bg-black opacity-75 transition-opacity"></div>
            ) : null}
            <div
                className={
                    `fixed z-[100] h-screen w-72 bg-skin-base shadow-md transition-[margin] duration-500 ease-in-out` +
                    startPositionClass + (!open ? marginClass : "")
                }>
                {children}
            </div>
        </>
    );
}