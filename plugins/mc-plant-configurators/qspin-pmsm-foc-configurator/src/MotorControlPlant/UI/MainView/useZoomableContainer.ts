import { log } from '@mplab_harmony/harmony-plugin-core-service';
import { useEffect, useRef, useState, WheelEvent, MouseEvent } from 'react';

const MIN_ZOOM_LEVEL = 0.4;
const MAX_ZOOM_LEVEL = 2;

export default function useZoomableContainer() {
  const containerRef = useRef<HTMLDivElement | null>(null);

  const [scaleSize, setScaleSize] = useState(1);

  useEffect(() => {
    if (containerRef.current) {
      containerRef.current.style.transformOrigin = 'top left';
    }
  }, [containerRef]);

  const resetZoom = () => {
    setScaleSize(1);
    if (containerRef.current) {
      const style = containerRef.current.style;
      style.transform = `scale(1)`;
      // Fix for the issue: setting scale to 1, sometimes doesn't hide the scrollbar.
      //setting the overflow property to 'hidden' and then 'auto' will fix the issue.
      style.overflow = `hidden`;
      setTimeout(() => (style.overflow = `auto`));
    }
  };

  const zoomIn = (value?: number) => {
    if (scaleSize > MAX_ZOOM_LEVEL) {
      return;
    }
    const newScaleSize = value || scaleSize + 0.02;
    setScaleSize(newScaleSize);
    if (containerRef.current) {
      containerRef.current.style.transform = `scale(${newScaleSize})`;
    }
  };

  const zoomOut = (value?: number) => {
    if (scaleSize < MIN_ZOOM_LEVEL) {
      return;
    }
    const newScaleSize = value || scaleSize - 0.02;
    setScaleSize(newScaleSize);
    if (containerRef.current) {
      containerRef.current.style.transform = `scale(${newScaleSize})`;
    }
  };

  const handleWheel = (event: WheelEvent<HTMLDivElement>): void => {
    if (event.altKey) {
      event.preventDefault();
      event.stopPropagation();

      if (event.deltaY > 0) {
        zoomOut();
      } else {
        zoomIn();
      }
    }
  };

  function handleMouseDown(event: MouseEvent<HTMLDivElement>): void {
    if (
      event.altKey &&
      event.button === 1 // middle mouse button/wheel click
    ) {
      resetZoom();
    }
  }

  return {
    ref: containerRef,
    zoomIn,
    zoomOut,
    resetZoom,
    props: {
      onWheel: handleWheel,
      onMouseDown: handleMouseDown
    }
  };
}
