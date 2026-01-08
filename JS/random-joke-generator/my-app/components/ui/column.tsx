import React from 'react'

interface ColumnProps {
    children: React.ReactNode,
    className: string
}
const Column: React.ForwardedRef<any> = (props) => {
    return (
        <div className={`flex flex-col ${props.className}`}>{props.children}</div>
    )
}


export default Column;